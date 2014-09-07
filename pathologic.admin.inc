<?php

/**
 * @file
 * Configuration form for Pathologic.
 */

/**
 * Form callback for the Pathologic configuration form.
 */
function pathologic_configuration_form($form, $form_state) {
  $form['reminder'] = array(
    '#type' => 'markup',
    '#markup' => '<p>' . t('Reminder: This form configures Pathologic&rsquo;s behavior globally, but in order for it to function on content in the first place, you must <a href="!path">add the Pathologic filter to the text formats</a> in use on this site. If confused, please read If confused, please read <a href="!docs">Pathologic&rsquo;s documentation</a> for a step-by-step guide to configuring Pathologic.', array('!path' => url('admin/config/content/formats'), '!docs' => 'http://drupal.org/node/257026')) . '</p>',
    '#weight' => 0,
  );
  $form['pathologic_protocol_style'] = array(
    '#type' => 'radios',
    '#title' => t('Processed URL format'),
    '#default_value' => variable_get('pathologic_protocol_style', 'full'),
    '#options' => array(
      'full' => t('Full URL (<code>http://example.com/foo/bar</code>)'),
      'proto-rel' => t('Protocol relative URL (<code>//example.com/foo/bar</code>)'),
      'path' => t('Path relative to server root (<code>/foo/bar</code>)'),
    ),
    '#description' => t('The <em>Full URL</em> option is best for stopping broken images and links in syndicated content (such as in RSS feeds), but will likely lead to problems if your site is accessible by both HTTP and HTTPS. Paths output with the <em>Protocol relative URL</em> option will avoid such problems, but feed readers and other software not using up-to-date standards may be confused by the paths. The <em>Path relative to server root</em> option will avoid problems with sites accessible by both HTTP and HTTPS with no compatibility concerns, but will absolutely not fix broken images and links in syndicated content.'),
    '#weight' => 10,
  );
  $form['pathologic_local_paths'] = array(
    '#type' => 'textarea',
    '#title' =>  t('All base paths for this site'),
    '#default_value' => variable_get('pathologic_local_paths', ''),
      '#description' => t('If this site is or was available at more than one base path or URL, enter them here, separated by line breaks. For example, if this site is live at <code>http://example.com/</code> but has a staging version at <code>http://dev.example.org/staging/</code>, you would enter both those URLs here. If confused, please read <a href="!docs">Pathologic&rsquo;s documentation</a> for more information about this option and what it affects.', array('!docs' => 'http://drupal.org/node/257026')),
    '#weight' => 20,
  );
  return system_settings_form($form);
}